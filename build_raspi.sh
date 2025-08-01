# build project
cmake --build build

# Change ownership the way that audio AND gpio access works
sudo chown root:root build/SoundTest
sudo chmod 4755 build/SoundTest