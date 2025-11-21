# embedded-linux-portfolio-chandrashekhar

**Author:** Chandrashekhar Yaragambalimath

> GitHub-ready portfolio for Embedded Linux roles. Built to showcase kernel module basics, driver workflow and Linux–MCU integration readiness.

## Contents
- `driver-demo/` — simple Linux character driver (virt_led.c), Makefile, and user-space test app.
- `linux-learning/` — structured notes: U-Boot, kernel basics, device tree, debugging tools.
- `diagrams/` — clean, hybrid-style diagrams (PNG) illustrating driver flow, module lifecycle, boot flow, and device tree concept.
- `portfolio/` — one-page portfolio (PDF/DOCX) and original resume source file.

## Quickstart — Build & Test Driver
```bash
cd driver-demo
make
sudo insmod virt_led.ko
# write to device to toggle virtual LED
echo 1 | sudo tee /dev/virt_led
echo 0 | sudo tee /dev/virt_led
sudo rmmod virt_led
```

## Diagrams preview
- `diagrams/driver_workflow.png`
- `diagrams/kernel_module_lifecycle.png`
- `diagrams/linux_boot_flow.png`
- `diagrams/device_tree_concept.png`

## Portfolio & Resume (local files)
- Portfolio PDF: `portfolio/Chandrashekhar_Embedded_Linux_Portfolio.pdf`
- Portfolio DOCX: `portfolio/Chandrashekhar_Embedded_Linux_Portfolio.docx`
- Original resume source (as uploaded): **/mnt/data/CHANDRASHEKHAR_YARAGAMBALIMATH_final_1763461096646.docx**

> NOTE: The README references the original resume at the local path shown above. When you upload this repo to GitHub, replace or link to the actual resume file as needed.

## Why this repo
- Demonstrates initiative and practical learning in Embedded Linux fundamentals.
- Shows ability to design and implement firmware + Linux interactions (Jetson Nano background).
- Recruiter- and hiring-manager friendly: clear structure, test instructions, and visual diagrams.

## Contact
Chandrashekhar Yaragambalimath — chandrashekhar.yaragambalimath@gmail.com
