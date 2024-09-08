# client.py
# Joseph Gareri
# 00099183
# jgareri@my.athens.edu
# Asg 02
# Expanded on previous assignment which utilized large language model.

import socket
import time
import random
from datetime import datetime
from threading import Thread

HOST = '127.0.0.1'
PORT = 65432
clients = {} 
log_file = 'server_log.txt'

def log(message):
    with open(log_file, 'a') as f:
        f.write(f"{datetime.now()} - {message}\n")

def broadcast_time():
    while True:
        if clients:
            timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            message = f"Timestamp: {timestamp}"
            for client_id, client_addr in clients.items():
                with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                    s.sendto(message.encode(), client_addr)
                log(f"Sent to client {client_id}: {message}")
            time.sleep(random.randint(5, 30))

def handle_client(conn, addr):
    data = conn.recv(1024).decode().strip()
    if data.startswith('R'):
        client_id = data.split()[1]
        clients[client_id] = addr
        log(f"Client {client_id} registered with address {addr}")
    elif data.startswith('U'):
        client_id = data.split()[1]
        if client_id in clients:
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
            handle_client(conn, addr)

if __name__ == "__main__":
    main()