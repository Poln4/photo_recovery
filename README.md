# Recover — JPEG Forensics (C)

**Goal:** Recover deleted JPEGs from a raw memory card image by scanning 512-byte blocks for JPEG signatures.

## How it works
1. Reads the memory card file in 512-byte chunks.
2. Detects JPEG headers (`0xff 0xd8 0xff 0xe0` / `0xe1`).
3. Writes each detected image to sequential files like `000.jpg`, `001.jpg`, etc.

## Run
```bash
make recover
./recover card.raw
