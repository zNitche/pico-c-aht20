# pico-c-aht20
PicoSDK (C) module for AHT20 temperature &amp; humidity sensor

#### Features
- sensor initialization & state management
- reading temperature & humidity

#### Usage
Example at [example.c](src/example.c)

#### Connect to device
```
screen /dev/tty1
```

to exit 
```
CTRL + A -> CTRL + \
```

#### Development setup (devcontainer)

1. get pico-sdk
```
mkdir -p ~/SDKs/pico-sdk
cd ~/SDKs/pico-sdk
git clone -b "2.2.0" --single-branch https://github.com/raspberrypi/pico-sdk.git 2.2.0
```

2. initialize dependencies
```
cd ~/SDKs/pico-sdk/2.2.0
git submodule update --init
```

3. open project in devcontainer
4. setup project

```
cmake -S . -B build
```

or for debug mode

```
cmake -DDEBUG=1 -S . -B build
```

5. build
```
cd build
make
```

6. enable auto copying of `.uf2` file to MCU
```
sh copy_uf2.sh ./build/example.uf2 /Volumes/RPI-RP2
```

### Resources
- [Datasheet](https://cdn-learn.adafruit.com/assets/assets/000/123/394/original/Data_Sheet_AHT20.pdf)
