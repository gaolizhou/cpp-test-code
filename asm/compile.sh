#!/bin/bash
for PROGRAM in *.asm; do
        yasm -f elf64  -g dwarf2 $PROGRAM && ld ${PROGRAM/%.asm/.o} -o ${PROGRAM%%.asm}
        rm ${PROGRAM/%.asm/.o}
done
