FROM arm32v7/python:3.11-buster

RUN apt update && apt install -y python3-rpi.gpio

WORKDIR /app

COPY requirements.txt requirements.txt

RUN pip install -r requirements.txt --no-cache-dir

COPY homelab_python/ ./homelab_python/

ENTRYPOINT [ "python", "-m", "homelab_python" ]