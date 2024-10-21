import socket

# Define server IP and port
SERVER_IP = '127.0.0.1'  # Localhost for testing purposes
SERVER_PORT = 8989       # A random port above 1024
BUFFER_SIZE = 1024        # Maximum message size

def start_server():
    # Create a TCP/IP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to the address (IP and port)
    server_socket.bind((SERVER_IP, SERVER_PORT))

    # Enable the server to listen for connections (backlog of 5)
    server_socket.listen(5)
    print(f"Server listening on {SERVER_IP}:{SERVER_PORT}")

    while True:
        # Wait for a connection
        client_socket, client_address = server_socket.accept()
        print(f"Connected by {client_address}")

        try:
            # Receive message from the client (up to 1024 bytes)
            data = client_socket.recv(BUFFER_SIZE)
            if not data:
                break
            print(f"Received message: {data.decode('utf-8')}")

            # Send a response back to the client
            response = "Message received".encode('utf-8')
            client_socket.sendall(response)

        finally:
            # Close the client socket
            client_socket.close()

if __name__ == '__main__':
    start_server()