#!/usr/bin/env python3
from gooey import Gooey

if __name__ == '__main__': 
    __name__ = ""
    exec(open(".cli_rename_equation").read())
    __name__ = "__main__"
else:
    exec(open(".cli_rename_equation").read())

@Gooey(
    show_success_modal=False
)
def main_gui():
    main()

if __name__ == '__main__':
    main_gui()
