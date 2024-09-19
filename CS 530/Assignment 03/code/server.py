# client.py
# Joseph Gareri
# 00099183
# jgareri@my.athens.edu
# Asg 03
# Expanded on previous assignment which utilized large language model.

import socket
import time
import random
from datetime import datetime
from threading import Thread, Lock

HOST = '127.0.0.1'
PORT = 65432
clients = {}
clients_lock = Lock()  # Lock to ensure thread-safe access to clients dictionary
log_file = 'server_log.txt'

def log(message):
    with open(log_file, 'a') as f:
        f.write(f"{datetime.now()} - {message}\n")

def broadcast_time():
    while True:
        if clients:
            timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            message = f"Timestamp: {timestamp}"
            with clients_lock:  # Ensure thread-safe access to clients dictionary
                client_keys = list(clients.keys())
            
            for client_id in client_keys:
                client_conn = clients[client_id]
                try:
                    client_conn.sendall(message.encode())
                    log(f"Sent to client {client_id}: {message}")
                except:
                    client_conn.close()
                    with clients_lock:
                        del clients[client_id]
        time.sleep(random.randint(5, 30))

def handle_client(conn, addr):
    data = conn.recv(1024).decode().strip()
    if data.startswith('R'):
        client_id = data.split()[1]
        with clients_lock:
            clients[client_id] = conn
        log(f"Client {client_id} registered with address {addr}")
    elif data.startswith('U'):
        client_id = data.split()[1]
        with clients_lock:
            if client_id in clients:
                clients[client_id].close()
                del clients[client_id]
        log(f"Client {client_id} unregistered")

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        print(f"Server listening on {HOST}:{PORT}")
        Thread(target=broadcast_time, daemon=True).start()
        while True:
            conn, addr = s.accept()
            Thread(target=handle_client, args=(conn, addr)).start()

if __name__ == "__main__":
    main()