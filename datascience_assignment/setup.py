import setuptools

with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

setuptools.setup(
    name="ASSIGNMENTQS2", 
    version="0.0.1",
    author="Abhishek Gandhi",
    author_email="abhigandhi29@gmail.com",
    description="Data Analysis package",
    long_description=long_description,
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: Linux",
    ],
    packages=['my_package', 'my_package.data', 'my_package.data.transforms', 'my_package.analysis'],
    python_requires='>=3.6',
)