# bash'd

bash'd is a simple daemon process, which executes a command on SIGUSR1

## Why

Because why not. I wanted to `swaylock` from `/usr/lib/systemd/system-sleep/` and didn't bother googling

## Usage

1. Clone with `git clone https://github.com/opekope2/bashd.git`
2. `cd bashd`
3. Compile/install
    a. If you use Arch BTW, install with `makepkg -si`
    b. If you don't use Arch BTW, compile with `gcc -o bashd bashd.c`
4. Start with `bashd command some_id_for_pkill` (arguments after `command` are ignored by bash'd, they can be used to identify the process with pkill)
5. Execute `command` with `pkill -SIGUSR1 -f some_id_for_pkill`

## Example

[My Hyprland rice #1](https://github.com/opekope2/dotfiles/blob/a5620b9855075e5b9a8f09cd368993365f1fb3ce/.config/hypr/autorun.conf#L13)

```bash
# Start bash'd
bashd 'swaylock -f' lock_screen_with_swaylock

# Lock screen
pkill -SIGUSR1 -f lock_screen_with_swaylock
```
