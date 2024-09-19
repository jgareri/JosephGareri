# client.py
# Joseph Gareri
# 00099183
# jgareri@my.athens.edu
# Asg 03
# Expanded on previous assignment which utilized large language model.

import socket
import time
import random
import sys
import signal
from threading import Thread

HOST = '127.0.0.1'
PORT = 65432
client_id = str(random.randint(1, 101))
message_file = f'client_{client_id}_messages.txt'
should_exit = False

def unregister_client():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(f"U {client_id}".encode())

def register_client():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(f"R {client_id}".encode())

def listen_for_messages():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        while not should_exit:
            data = s.recv(1024)
            if data:
                with open(message_file, 'a') as f:
                    f.write(f"{data.decode()}\n")
            else:
                break

def signal_handler(sig, frame):
    print("Received exit signal, unregistering client...")
    unregister_client()
    global should_exit
    should_exit = True
    sys.exit(0)

def main():
    signal.signal(signal.SIGINT, signal_handler)
    register_client()
    listener_thread = Thread(target=listen_for_messages, daemon=True)
    listener_thread.start()
    sleep_time = random.randint(15, 90)
    time.sleep(sleep_time)
    unregister_client()
    print(f"Client {client_id} unregistering after {sleep_time} seconds")

if __name__ == "__main__":
    main()