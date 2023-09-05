# bash'd

bash'd is a simple daemon process, which executes a command on SIGUSR1

## Why

Because why not. I wanted to `swaylock` from `/usr/lib/systemd/system-sleep/` and didn't bother googling

## Usage

1. Compile with `gcc -o bashd bashd.c`
2. Start with `bashd command some_id_for_pkill` (arguments after `command` are ignored by bash'd, they can be used to identify the process with pkill)
3. Execute `command` with `pkill -SIGUSR1 -f some_id_for_pkill`

## Example

```bash
# Start bash'd
bashd 'swaylock -f' run_swaylock

# Lock screen
pkill -SIGUSR1 -f run_swaylock
```
