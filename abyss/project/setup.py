from setuptools import setup, Extension

package_data = {"abyss": ["core.so", "core.pyi"]}



setup(
    name="abyss",
    version="0.1.0",
    description="TAUV-Control (Abyss) for smart decision taking, remote or indevice underwater vehicle control.",
    package_data=package_data,
    zip_safe=False,

    entry_points={
        "console_scripts": [
            "abyss=abyss.cli:main"
        ],
    },
)
