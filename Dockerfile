FROM arm32v7/python:3.11-buster@sha256:8f2bd14b189d47dace1078d36b2159837f4a41f24ab68179bfd73efdfc4f36a9

RUN apt update && apt install -y python3-rpi.gpio

WORKDIR /app

COPY requirements.txt requirements.txt

RUN pip install -r requirements.txt --no-cache-dir

COPY homelab_python/ ./homelab_python/

ENTRYPOINT [ "python", "-m", "homelab_python" ]