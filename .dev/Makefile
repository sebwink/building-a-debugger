.PHONY: image

PROJECT := $(shell cat project)

image:
	docker build . -t sebwink/$(PROJECT):local
