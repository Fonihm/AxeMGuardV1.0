<p align="center">
  <img src="https://github.com/Fonihm/Fonihm/blob/main/Mine.jpg?raw=true" alt="AxeM Logo" width="25%">
</p>

<h1 align="center">AxeMGuard v1.0 </h1>

<p align="center">
  <strong>AxeMGuard</strong> is a compact, low-level memory leak tracker for C. It is designed for developers who want to monitor allocations, prevent memory corruption, and ensure clean resource management.
</p>

<p align="center">
  The module is compiled as a standalone <strong>Dynamic-Link Library (DLL)</strong> and uses zero-conflict hooking mechanics.
</p>

---

## 🛠️ Key Features

| Feature | Description |
| :--- | :--- |
| **⚡ Zero-Conflict Hooking** | Isolates macro overrides to user scripts, preventing recursive loops inside the library engine itself. |
| **📋 Comprehensive Logging** | Tracks and updates the exact memory address, allocation size, filename, and source code line. |
| **🚀 Modularity (DLL)** | Compiles into an independent `.dll` file that can be linked with any external C application. |
| **🧠 Lightweight Architecture** | Utilizes a fast static array internal registry with minimal processing overhead. |

---

## 🕹️ Architecture & Mechanism

AxeMGuard operates as an interception layer between the user application and the operating system's memory allocator:

### 1. Interception (Hooking)
When the user requests memory via standard allocator calls, AxeMGuard intercepts the request using preprocessor macros, capturing context data before invoking the system allocator.

### 2. The Internal Ledger
The tracker records metadata inside an internal registry array, linking the allocated memory block to the exact file and line number.
> 

### 3. Leak Verification
Upon completion, the tracking engine scans the unreleased registry rows. Any active memory blocks are flagged and outputted directly to the console.
