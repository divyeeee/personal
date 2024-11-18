from http.server import BaseHTTPRequestHandler, HTTPServer

# Define the handler to manage incoming requests
class MyRequestHandler(BaseHTTPRequestHandler):
    # Handle GET requests
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(b"Hello, this is a basic HTTP server!")

    # Handle POST requests
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        
        # For demonstration, we'll just print the received data
        print(f"Received POST data: {post_data.decode('utf-8')}")
        
        self.send_response(200)
        self.send_header("Content-type", "application/json")
        self.end_headers()
        self.wfile.write(b'{"status": "success"}')

# Define the server address and port
server_address = ('192.168.182.181', 8080)  # '' means listen on all interfaces
httpd = HTTPServer(server_address, MyRequestHandler)

print("Starting server on port 8080...")
httpd.serve_forever()