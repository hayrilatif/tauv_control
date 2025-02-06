import os
import subprocess
import sys

DIR = "abyss/" #so dosyasi ve pyi kayit yolu

os.makedirs(DIR, exist_ok=True)

# stubgen bulsun diye gecici python yolu degistirme
env = os.environ.copy()
env["PYTHONPATH"] = DIR

module_name = "core" #abyss.core degil sadece core cunku abyss ust modülü python paketi

try:
    subprocess.run(["pybind11-stubgen", module_name, "--output-dir", DIR], env=env, check=True)
    print(f"Stubs generated successfully in {DIR}")
except subprocess.CalledProcessError as e:
    print(f"Error while generating stubs: {e}")
    sys.exit(1)
