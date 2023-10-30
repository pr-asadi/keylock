# Keylock

Keylock is a simple alternative to [kfv/keylock](https://github.com/kfv/keylock).
It uses Xlib to lock the keyboard and mice/mouse.
Quit/Unlock, with pressing CTRL+ALT+u.
> Keys like audio lower/raise and play/pause are not locked.
> CTRL+ALT+{F1,F2,F3,F4,F5,F6} combination is not locked as well.

## Installation

```
make install
```
or
```
make PREFIX=/usr/local install
```
> Note: `keylock` will be copied to `~/.local/bin` directory by default.

## Usage

Simply execute/run `keylock` on a terminal emulator, or from `dmenu`.
