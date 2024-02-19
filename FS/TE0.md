---
marp: true
author: Joppe Blondel
paginate: true
title: TE0
size: 16:9
footer: Engineero Full Stack Tech Event 2024 - Devcontainers, the Why, What and How
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
# Devcontainers, the Why, What and How
#### Down the rabbit hole to stay

---
# What's the problem?
* Machine setup...
  * Install this, that, ow and this, and hey don't forget that 
  * Version hell and clashes with already installed tools
* "It works on my machine..."
* Linter/formatter rules not correctly applied
  * Frustrated developers
  * Frustrated maintainers
  * ...

---
# Can we solve it?
* Stop complaining andd just install the lot
* Remote development (e.g. over ssh)
* Combine all tools, libraries and the lot in one package
    * VM
        <!-- Quite the resource hog -->
    * Snap/Flatpack/AppImage
        <!-- snap: ubuntu only -->
        <!-- AppImage: lack of udates -->
        <!-- All on linux only and more for 1 application -->
    * (Docker) container
        <!-- Lightweight like above and has native windows (with wsl) support, but best with: -->
    * Devcontainer with IDE supporting them

---
# So... devcontainers... what are they?
[containers.dev](https://containers.dev/): *A development container (or dev container for short) allows you to use a **container** as a full-featured development environment. It can be used to run an application, to separate tools, libraries, or runtimes needed for working with a codebase, and to aid in continuous integration and testing. ...*

---
# Down the rabbit hole: containers
*... you to use a **container** as a full-featured ...*
* Sandbox environment
* Like a VM: full OS
* Lightweight: uses kernel of the host
* Declarative: Infrastructure as Code
* Integration with lots of tools

---
# Down the rabbit hole: containers
They are used for:
* Easy deployment of (web) applications
* Micro-services on a (kubernetes) cluster
* Packaging of software and dependencies
    * running software locally
    * packaged software for use in CI/CD

---
# Like a VM and lightweight
Applications on top of OS
![bg right 80%](../img/sch_container0.png)

---
# Like a VM and lightweight
Applications in VM's
![bg right 80%](../img/sch_container1.png)

---
# Like a VM and lightweight
Applications in Docker containers

[Alpine](https://www.alpinelinux.org/about/): *... A container requires no more than **8 MB** ...*
![bg right 80%](../img/sch_container2.png)

---
### Declarative: Infrastructure as Code
```Dockerfile
FROM node:10-alpine

RUN mkdir -p /app && chown -R node:node /app
WORKDIR /app
USER node

CMD /bin/sh
```

* To create a container image: 
    `docker build --tag 'node_example' .`

---
# Declarative: Infrastructure as Code
* To run a container image: 
    `docker run -it 'node_example'`
* This will get you a Debian shell
    ```bash
    $ docker run -it node_example
    /app $ pwd
    app
    /app $ whoami
    node
    /app $ 
    ```

---
# Containers and Docker
![bg center 55%](https://logos-world.net/wp-content/uploads/2021/02/Docker-Symbol.png)
<!-- Docker released and published in 2013 -->
<!-- 2015 startd the OCI (open container initiative): not just docker anymore: podman/containerd/lxd -->

---
# Example: Node app on Docker
* Note: **not** the app as Docker container, but development in Docker container
* `docker run -it -p 80:8080 -v .:/app node_example`
  * `-it`: interactive -> stay in terminal
  * `-p 80:8080`: map port 8080 from the container to port 80 on the host
  * `-v .:/app`: mount the current directory (`.`) to `/app` in the container
  
---
# Example: Node app on Docker
* \+ Working on local machine
* \+ Whatever IDE you want
* \- Building and running from terminal
* \- No IDE-integrated debugging

---
# Devcontainers: containers with spice
![bg center 60%](https://containers.dev/img/dev-container-stages.png)

---
# Devcontainers: containers with spice
* Full development environment
* Utilities and personalization
* Configuration of IDE
  * git with credentials
  * debugger

---
# You should like VSCode...
* [Supported tools](https://containers.dev/supporting)
  * VSCode
  * Visual Studio >2022 for C++
  * IntelliJ IDEA (early support)
  * CLI, Cachix devenv, Jetpack.io Devbox
  * Github Codespaces, CodeSandbox, DevPod, Schema

---
# Devcontainers and VSCode
![bg center 60%](../img/sch_devcontainer_vscode.png)

---
# Devcontainers: an example
```json
{
    "build": { "dockerfile" : "Dockerfile" },
    "customizations": {
        "vscode": {
            "extensions" : [
                "ms-vscode.js-debug",
                "leizongmin.node-module-intellisense"
            ]
        }
    },
    "forwardPorts": [ 8080 ]
}
```

---
# Devcontainers and VSCode
* Seamless: functions as local instance
* Executes build tools, debugger and other tools from container
* VSCode Configuration and plugins declared in the json file
* Make sure to install the Dev Containers plugin `ms-vscode-remote.remote-containers`
* Good to use `mcr.microsoft` docker images as BASE:
  * `mcr.microsoft.com/vscode/devcontainers/javascript-node`

---
# Docker on Windows
Docker is in it's core a linux tool

* Containers themselves on WSL
* USB to WSL: USBIP
    * see readme
![bg right 90%](../img/sch_docker_on_windows.png)

