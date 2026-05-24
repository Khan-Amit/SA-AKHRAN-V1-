#!/bin/bash
# SA-AKHRAN Installer – compiles backend, sets up front end
# Run: chmod +x setup.sh && ./setup.sh

set -e

echo "🛡️ SA-AKHRAN – Sluice Activated Guard"
echo "====================================="
echo "Installing backend filters..."

# Compile the three tiers
gcc backend/sluice-bench-1.c -o backend/sluice1
gcc backend/sluice-bench-2.c -o backend/sluice2
gcc backend/sluice-bench-3.c -o backend/sluice3

echo "✅ Backend compiled."

# Copy front end to web directory (if needed)
if [ -d "/var/www/html" ]; then
    sudo cp frontend/index.html /var/www/html/
    echo "✅ Front end installed to /var/www/html/"
else
    echo "⚠️ Web server not found. Front end remains in ./frontend/"
fi

echo ""
echo "🎉 Installation complete."
echo "To run the full pipeline:"
echo "  cat data.txt | ./backend/sluice1 | ./backend/sluice2 | ./backend/sluice3 > filtered.txt"
echo ""
echo "To start the web dashboard: open frontend/index.html in a browser."
