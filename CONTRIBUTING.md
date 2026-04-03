# 🤝 Contributing to data-structures-in-C

First off, thank you for taking the time to contribute! Whether you're fixing a typo, adding a new program, or improving an explanation — every contribution matters and is appreciated.

This guide is written with absolute beginners in mind, so don't worry if you're new to GitHub or open source. We'll walk you through everything step by step.

---

## 🍴 Forking vs Cloning — What's the Difference?

Before we begin, it's important to understand two key concepts:

- **Forking** — Creates your own personal copy of this repo *on GitHub*. This is where you'll make your changes, without affecting the original repo.
- **Cloning** — Downloads a copy of a repo *to your local machine* so you can work on it.

In short: you **fork** on GitHub, then **clone** your fork to your computer.

---

## 🔀 Branches — Why Not Just Use Main?

The `main` branch is the stable, production-ready version of the repo. Instead of making changes directly to it, you create your own **branch** — think of it as your own isolated workspace. Once your changes are reviewed and approved, they get merged into `main`.

This keeps things clean and ensures nothing breaks for everyone else while you're working.

---

## 🚀 Step-by-Step Contribution Workflow

### 1. Fork the repo
Click the **Fork** button on the top right of this repo's GitHub page. This creates a copy of the repo under your GitHub account.

### 2. Clone your fork
```bash
git clone https://github.com/your-username/data-structures-in-C.git
cd data-structures-in-C
```

### 3. Create a new branch
Name your branch something simple and descriptive:
```bash
git checkout -b add-merge-sort
```

Some examples:
- `add-merge-sort` — for adding a new program
- `fix-binary-search` — for fixing a bug
- `update-readme` — for documentation changes

### 4. Make your changes
Add your program, fix a bug, or improve an explanation. Make sure to follow the [Code Style](#-code-style) and [Naming Conventions](#-naming-conventions) guidelines below.

### 5. Stage and commit your changes
```bash
git add .
git commit -m "Add merge sort implementation"
```

Write commit messages that clearly describe what you did — keep them short but meaningful.

### 6. Push your branch
```bash
git push origin add-merge-sort
```

### 7. Open a Pull Request
Go to your forked repo on GitHub and click **Compare & pull request**. Add a brief description of what you've done and submit it. We'll review it and get back to you!

---

## 🎨 Code Style

Keeping the code consistent makes it easier for everyone to read and learn from it.

- **Indentation** — Use 4 spaces for indentation. Avoid tabs.
- **Comments** — Add a brief comment above any logic that isn't immediately obvious. A beginner should be able to follow along.
  ```c
  // Swap two elements using a temporary variable
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
  ```
- **Meaningful variable names** — Avoid single letter names like `a`, `b`, `x`. Use names that describe what the variable holds.
  ```c
  // ❌ Avoid
  int x = 10;

  // ✅ Prefer
  int array_size = 10;
  ```
- **Keep it simple** — This repo is a learning resource. Prefer clarity over cleverness.

---

## 📁 Naming Conventions

To keep the repo structure consistent, please follow these conventions:

- **File names** — Use lowercase with underscores. Example: `merge_sort.c`, `stack_array.c`
- **Branch names** — Use lowercase with hyphens. Example: `add-merge-sort`, `fix-binary-search`
- **Place your file in the right unit folder** — Refer to the repo structure in the [README](README.md) to find where your program belongs.

---

## ✅ What Kind of Contributions Are Welcome?

- Adding a new program that fits into an existing unit
- Fixing incorrect logic or bugs in existing programs
- Improving comments or explanations to make code easier to understand
- Fixing typos or improving the README/documentation
- Suggesting improvements via GitHub Discussions

---

## 🌱 A Note on Community

This repo welcomes contributors of all levels. If you're a beginner making your very first pull request, that's wonderful — we were all there once. Be patient with the review process, and don't hesitate to ask questions via GitHub Discussions if you're stuck.

Let's keep this a kind and encouraging space for everyone. 😊

---

## 📄 License

By contributing, you agree that your contributions will be licensed under the [MIT License](LICENSE).