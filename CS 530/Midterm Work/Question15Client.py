import socket

# Define server IP and port
SERVER_IP = '127.0.0.1'  # Localhost for testing purposes
SERVER_PORT = 8989       # The port the server is listening on
BUFFER_SIZE = 1024       # Maximum message size

def start_client():
    # Create a TCP/IP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    try:
        # Connect the socket to the server's port
        client_socket.connect((SERVER_IP, SERVER_PORT))
        
        while True:
            # Prompt the user for a message
            message = input("Enter message (type 'STOP' to quit): ")
            
            # Exit the loop if the user types 'STOP'
            if message == "STOP":
                print("Exiting the client.")
                break
            
            # Ensure the message is exactly 1024 bytes
            message = message.ljust(BUFFER_SIZE)[:BUFFER_SIZE]
            
            # Send the message to the server
            client_socket.sendall(message.encode('utf-8'))
            
            # Receive response from the server
            response = client_socket.recv(BUFFER_SIZE)
            print(f"Server response: {response.decode('utf-8').strip()}")
    
    finally:
        # Close the client socket
        client_socket.close()

if __name__ == '__main__':
    start_client()