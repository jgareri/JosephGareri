# traceroute.py
# Joseph Gareri
# 00099183
# jgareri@my.athens.edu
# Asg 06

import argparse
from scapy.all import traceroute

def perform_traceroute(destination):
    """
    Perform a traceroute to the specified destination.
    
    Parameters:
    - destination (str): The hostname or IP address to traceroute.
    """
    print(f"Tracing route to {destination}...\n")
    
    # Call scapy's traceroute function
    # maxttl: Maximum number of hops (TTL)
    # verbose: Verbosity level (0 for minimal output)
    ans, unans = traceroute(destination, maxttl=30, verbose=0)
    
    # Display the results of the traceroute
    print("\nTraceroute Results:")
    ans.show()

if __name__ == "__main__":
    # Set up argument parser
    parser = argparse.ArgumentParser(description='Perform a traceroute to a specified destination.')
    parser.add_argument('destination', type=str, help='The hostname or IP address to traceroute to')

    # Parse arguments
    args = parser.parse_args()

    # Perform traceroute using provided destination
    perform_traceroute(args.destination)