import subprocess

print("\nUpdating submodules...")
subprocess.call(["git", "submodule", "update", "--init", "--recursive"])