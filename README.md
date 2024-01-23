# README for Organized Project

## Introduction

Welcome to the Organized Project, a robust command-line tool designed for efficient management and sorting of materials. This project is focused on handling large quantities of items, providing a streamlined interface for storing, sorting, and managing hardware efficiently.

## Features

- **Command System**: Incorporates `add`, `del`, `disp`, and `sort` commands for comprehensive inventory management.
  - `add`: Allows adding new items with unique identifiers, categorized by type and name.
  - `del`: Enables item removal using their identifiers for easy inventory management.
  - `disp`: Displays the current inventory, listing all stored items.
  - `sort`: Offers sorting of items based on criteria like TYPE, NAME, and ID, including reverse sorting capability.

- **Efficient Sorting and Storage**: Tailored to handle a large volume of items, ensuring quick and efficient organization.
- **Multi-tag Sorting**: Supports sorting by multiple tags at once, providing an organized and prioritized view of materials.

## Getting Started

### Prerequisites

Ensure you have the following installed:
- A C compiler (GCC recommended)
- Make

### Installation

```bash
git clone git@github.com:Haloys/organized.git
cd organized
```

```bash
make
```

## Usage Instructions

```bash
# Start the program
./organized
```

# Add items
```
Workshop » add WIRE usb
Workshop » add ACTUATOR button, DEVICE recorder
```

# Display current inventory
```
Workshop » disp
```

# Delete an item
```
Workshop » del 1
```

# Sort items by NAME in reverse order
```
Workshop » sort NAME -r
```

# Display sorted inventory
```
Workshop » disp
```

# Advanced sorting: sort by TYPE in reverse, then by NAME, and ID in reverse
```
Workshop » sort TYPE -r NAME ID -r
Workshop » disp
```