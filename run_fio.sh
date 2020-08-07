#!/bin/bash

rm -rf /mnt/pmem_emul/*
LD_PRELOAD=./splitfs/libnvp.so ../applications/fio-fio-3.17/fio --name=random-writers --ioengine=sync --iodepth=1 --rw=write --bs=4k --size=64m --numjobs=1 --directory=/mnt/pmem_emul
