#!/bin/bash

cd godot-cpp
scons platform=linux -j15 custom_api_file=../extension_api.json
cd ..