FROM alpine:3.14
RUN apk add --no-cache meson
ENTRYPOINT [ "./install.sh" ]