FROM python:3.9-alpine

WORKDIR /app

COPY requirements.txt /

RUN pip install --no-cache-dir -r /requirements.txt

COPY homelab_python/ ./homelab_python/

ENTRYPOINT [ "python", "-m", "homelab_python" ]