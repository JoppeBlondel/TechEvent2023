---
marp: true
author: Joppe Blondel
paginate: true
title: TechEvent1
size: 16:9
footer: Engineero Embedded Tech Event 2023 - How-to and some notes
theme: gaia
style: |
  :root {
    --color-background: #eee;
    --color-foreground: #333;
    --color-highlight: #f96;
    --color-dimmed: #888;
  }
  section > footer {
    color: #fff;
    background: #000761;
    font-size: medium;
    height: 8%
  }
  section::after {
    color: #fff;
    font-size: medium;
    height: 8%
  }
  img[alt~="center"] {
    display: block;
    margin: 0 auto;
  }
---

<!-- _class: lead -->
# Devcontainers and Embedded software development
#### Try-out STM32 devcontainer

---
# Required linux programs
* arm gcc (arm-none-eabi)
* gdb
* make (provided in `build-essential`)
* openocd
* usbutils (provides `lsusb`)

---
# Blinky on FreeRTOS
Simple example CubeMX generated project can be found at
[github](https://github.com/JoppeBlondel/TechEvent2023/tree/main/examples/bluepill_freertos_blinky_sources) in the repo

nothing to specifically focus on. LED blinking done in `Src/freertos.c`

Flashing with OpenOCD: example in `flash.sh`

---
# Integration with VSCode
* Create VSCode build task
    * `.vscode/tasks.json` with entry for shell executing `make`
* Maybe a flash task as well
* Add task explorer plugin to devcontainer
* Add debug entry for vscode (see next slide)

---
# OpenOCD debugging in VSCode
* Add cortex-debug plugin to devcontainer
* Let VSCode create a `launch.json` and let it add a cortex-debug entry
* Set the servertype to `openocd`
* For automatic building add a `preLaunchTask` and set it to the build task name
* For automatic programming add an array called `postLaunchCommands` with `load` and `monitor resume`

---
* add the OpenOCD scripts for the debugger and chip: add
```json
"configFiles": [
    "interface/stlink.cfg",
    "target/stm32f1x.cfg"
]
```
* At last: force cortex-debug to use gdb-multiarch with
`"gdbPath": "gdb-multiarch"`


Set your breakpoints and pause and single step away!!

*For a full example check [github](https://github.com/JoppeBlondel/TechEvent2023/tree/main/examples/stm32_devcontainer_example)*