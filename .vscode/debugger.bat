set PATH=c:\Users\lgruc\.vscode\HusarionTools\bin\;%PATH%
cd d:\Users\lgruc\Desktop\Studia\Mechatronic Design\Projektowe\Telegraph_Project || exit 1
start /wait st-flash write myproject.bin 0x08010000 || exit 1
start st-util
arm-none-eabi-gdb %*