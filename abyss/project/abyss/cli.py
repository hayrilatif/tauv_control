import argparse
from importlib.metadata import version

#Arayüz yazarsak buradan baslatiriz toplu olur

def main():
   parser = argparse.ArgumentParser(description="Abyss CLI Tool")
   #parser.add_argument
   
   args = parser.parse_args()

   print(f"""
                     ##                                                                    ##                                 
╭━━━━━━━━╮┏━╮╭━┓   ######    ####    ##  ##   ##  ##                               ####    ##       ##  ##    #####    #####  
┃┈┈┈┈┈┈┈┈┃╰╮╰╯╭╯     ##         ##   ##  ##   ##  ##            ######                ##   #####    ##  ##   ##       ##      
┃╰╯┈┈┈┈┈┈╰╮╰╮╭╯┈     ##      #####   ##  ##   ##  ##                               #####   ##  ##   ##  ##    ####     ####   
┣━━╯┈┈┈┈┈┈╰━╯┃┈┈     ##     ##  ##   ##  ##    ####                               ##  ##   ##  ##    #####       ##       ##  
╰━━━━━━━━━━━━╯┈┈      ###    #####    #####     ##                                 #####   #####       ##    #####    #####   
                                                                                                    ####                      
TAUV-Control CLI
v0.1.0 (Abyss)
""")