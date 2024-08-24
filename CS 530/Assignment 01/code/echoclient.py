# echoclient.py
# Joseph Gareri
# 00099183
# jgareri@my.athens.edu
# Asg 01 
# Copied/Pasted Instructor Samples && Used basic help from large language model

import socket
from time import sleep, perf_counter_ns


HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432  # The port used by the server
NUM_TRIALS = 20

def measure_single_response_time():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
    
        start_time = perf_counter_ns()
    
        s.sendall(b"Hello, world")
    
        data = s.recv(1024)
    
        end_time = perf_counter_ns()
    
        total_time = end_time - start_time
    return total_time

response_times = []
for _ in range(NUM_TRIALS):
    response_time = measure_single_response_time()
    response_times.append(response_time)
    
average_response_time_ns = sum(response_times) / len(response_times)
average_response_time_ms = average_response_time_ns / 1_000_000  # Convert to milliseconds

print(f"Average response time over {NUM_TRIALS} trials: {average_response_time_ms:.2f} ms")