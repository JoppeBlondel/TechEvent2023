#!/bin/bash
openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program build/stm32_devcontainer_example.bin reset exit 0x08000000"