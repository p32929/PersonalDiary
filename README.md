# Personal Diary

A tiny diary for your terminal, written in C. Instead of a blank page, it asks you about the same few things every day, so writing a diary takes a minute. Each day is saved as its own plain text file that you can open anywhere.

This is one of my first C programs. It still works, and it is kept here as it was.

## Features

1. **Your own daily questions:** the first time you run it, you list the things you want to track, like "Study", "Exercise" or "Work".
2. **Quick daily entry:** each day it goes through your list and you type one line for each.
3. **Today or any date:** use today's date, or type a different date to fill in a day you missed.
4. **One file per day:** entries are saved in a `Diary` folder, one text file per date.
5. **Remembers your last entry,** so you can see when you last wrote.

## Build and run

You only need a C compiler (`gcc`, `clang` or MinGW). Use the newest file, `Personal diary 2.0.5.c`. The older files are kept for history.

```bash
gcc "Personal diary 2.0.5.c" -o diary
./diary
```

## How to use

1. First run: type the names of the things you want to track, one per line, and type `0` when you are done.
2. Choose `1` to use today's date, or `2` to type a date as `dd-mm-yyyy`.
3. For each item on your list, type what you did and press Enter.
4. Find your entries in the `Diary` folder next to the program.

To change your list, delete `Sub.txt` and `N.txt` and run it again.

## Changelog

1. **2.0.5:** bug fixes. You no longer have to say up front how many lines you will write.
2. **2.0.4:** bug fixes. Each day gets its own file in the `Diary` folder instead of one big `Diary.txt`.
3. **2.0.3:** bug fixes, and it shows your last entry.
4. **2.0.2:** bug fixes, numbers before each item, clearer prompts and a new date format.
5. **2.0.1:** bug fixes.
6. **2.0:** rewritten from scratch, with custom dates.
7. **1.0:** first version.

## Contributing

Contributions are very welcome, thank you! Before you start on a pull request, please open an issue and tell me what you would like to add or change. That way we can agree on it first, and your time is not wasted on something that might not fit. Thanks for helping make Personal Diary better.

## Share

<a href="https://p32929.github.io/share/?repo=PersonalDiary"><img src="https://p32929.github.io/readme/share.svg" alt="Share this with your friends in just a click" width="420"></a>

## Support

<a href="https://p32929.github.io/support/"><img src="https://p32929.github.io/readme/support.svg" alt="If you like my works and want to support me, feel free to support" width="420"></a>
