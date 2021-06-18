FROM arm32v7/python:3.9-buster

RUN apt update && apt install -y python3-rpi.gpio

WORKDIR /app

COPY requirements.txt /

RUN pip install --no-cache-dir -r /requirements.txt

COPY homelab_python/ ./homelab_python/

ENTRYPOINT [ "python", "-m", "homelab_python" ]