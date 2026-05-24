#!/usr/bin/env python3
import os
import sys

BLACKLIST_FILE = "blacklist.txt"
WHITELIST_FILE = "whitelist.txt"

def load_numbers(filepath):
    if not os.path.exists(filepath):
        return set()
    with open(filepath, 'r') as f:
        return {line.strip() for line in f if line.strip()}

def is_allowed(caller_number):
    blacklist = load_numbers(BLACKLIST_FILE)
    whitelist = load_numbers(WHITELIST_FILE)
    if caller_number in blacklist:
        return False
    if caller_number in whitelist:
        return True
    return False

def filter_call(caller_number):
    if is_allowed(caller_number):
        print(f"ALLOW: {caller_number} – encrypting channel")
        return True
    else:
        print(f"BLOCK: {caller_number} – dropped silently")
        return False

if __name__ == "__main__":
    if len(sys.argv) > 1:
        filter_call(sys.argv[1])
    else:
        print("Usage: voip_filter.py <caller_number>")
