#!/bin/bash
# SA-AKHRAN Installer – compiles backend, sets up front end
# Run: chmod +x setup.sh && ./setup.sh

set -e

echo "🛡️ SA-AKHRAN – Sluice Activated Guard"
echo "====================================="
echo "Installing backend filters..."

# Create backend directory if missing
mkdir -p backend

# Compile the three tiers (assumes source files are in backend/)
if [ -f backend/sluice-bench-1.c ]; then
    gcc backend/sluice-bench-1.c -o backend/sluice1
    echo "✅ Compiled sluice1 (pattern matching)"
else
    echo "⚠️ backend/sluice-bench-1.c not found – skipping"
fi

if [ -f backend/sluice-bench-2.c ]; then
    gcc backend/sluice-bench-2.c -o backend/sluice2
    echo "✅ Compiled sluice2 (stateful inspection)"
else
    echo "⚠️ backend/sluice-bench-2.c not found – skipping"
fi

if [ -f backend/sluice-bench-3.c ]; then
    gcc backend/sluice-bench-3.c -o backend/sluice3
    echo "✅ Compiled sluice3 (total isolation)"
else
    echo "⚠️ backend/sluice-bench-3.c not found – skipping"
fi

echo ""
echo "🎉 Installation complete."
echo "To run the full pipeline:"
echo "  cat data.txt | ./backend/sluice1 | ./backend/sluice2 | ./backend/sluice3 > filtered.txt"
echo ""
echo "To start the web dashboard: open index.html in a browser."
