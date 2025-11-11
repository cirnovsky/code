# run.py
import subprocess

solver = subprocess.Popen(
    ['python3', 'A.py'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True,
    bufsize=1
)

interactor = subprocess.Popen(
    ['python3', 'int.py'],
    stdin=solver.stdout,
    stdout=solver.stdin,
    text=True,
    bufsize=1
)

interactor.wait()
solver.wait()
