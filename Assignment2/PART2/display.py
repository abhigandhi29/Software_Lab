import tkinter.filedialog
import tkinter as tk
from tkinter import *
import tkinter.font as tkFont
from PIL import ImageTk, Image

class display_contacts:

    def __init__(self,user):
        self.root = Toplevel()
        self.root.title('Display Contacts')
        self.root.geometry("700x700")

        self.var = StringVar()
        self.var.set("Display Contacts")
        self.frameup = Frame(self.root, bg="blue", height="80")
        self.frameup.pack(fill=tk.X)
        self.title_font = tkFont.Font(family="Helvetica",size=32,weight="bold")
        self.title=Label(self.frameup,font=self.title_font,text="Display Contact",bg="blue")
        self.title.pack(side=TOP)
        

        self.framel = Frame(self.root, bg="black", height="5")
        self.framel.pack(fill=tk.X,pady=(0,10))

        self.frame_top = Frame(self.root)
        self.frame_top.pack(fill=tk.X)

        self.font = tkFont.Font(family="Helvetica",size=16,weight="bold")

        self.text = Text(self.frame_top,bg="white",fg="black",font=self.font,selectborderwidth="3")
        self.text.pack()

        self.message=user.id+" is in contact with: "+"\n"
        for i in user.contacts:
            self.message+= i+"\n"
        self.text.insert("1.0",self.message)


    def run(self):
        self.root.mainloop()