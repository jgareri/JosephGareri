# Traceroute Script

This is a simple traceroute tool built using Python and the `scapy` library. It traces the network path to a specified destination.

## Prerequisites

- Python 3.x
- `scapy` library: Install it with `pip install scapy`

## How to Run

1. **Open a Terminal**: Make sure it has administrator privileges.

2. **Run the Script**:

   ```bash
   python traceroute_script.py <destination>
   ```

   Replace `<destination>` with a domain name (e.g., `google.com`) or an IP address.

## Example

To trace the route to Google, you would run:

```bash
python traceroute_script.py google.com
```

## Limitations

- Requires administrator permissions.
- Firewalls may block the necessary ICMP packets.

## Troubleshooting

If you encounter issues:

- Ensure you are running as an administrator.
- Check that your firewall settings allow ICMP packets.