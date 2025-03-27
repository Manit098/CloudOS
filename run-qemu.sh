#!/bin/bash
qemu-system-x86_64 -drive format=raw,file=os.iso -m 1024 -display sdl
