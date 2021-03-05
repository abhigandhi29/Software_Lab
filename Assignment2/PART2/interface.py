import tkinter.filedialog
import tkinter as tk
from tkinter import *
import tkinter.font as tkFont
from PIL import ImageTk, Image
import post_message as pm
import display_group as dg
import display as cd
import incoming as rm

class Interface:

    def __init__(self,data_usr,data_grp):
        self.root = tk.Tk()
        self.root.title('Social_Media')
        self.root.geometry("700x700")
        self.image_loc = []
        self.current_user = data_usr[0].id
        self.data_usr = data_usr
        self.data_grp = data_grp
        users=[]
        for data in data_usr:
            users.append(data.id)


        self.var = StringVar()
        self.var.set("Social Media")
        self.frameup = Frame(self.root, bg="blue", height="80")
        self.frameup.pack(fill=tk.X)
        self.title_font = tkFont.Font(family="Helvetica",size=32,weight="bold")
        self.title=Label(self.frameup,font=self.title_font,textvariable=self.var,bg="blue")
        self.title.pack(side=TOP)
        

        self.framel = Frame(self.root, bg="black", height="5")
        self.framel.pack(fill=tk.X,pady=(0,10))

        variable = StringVar(self.root)
        variable.set(users[0])
        self.frame_top = Frame(self.root,borderwidth=5)
        self.frame_top.pack(fill=tk.X)

        self.font = tkFont.Font(family="Helvetica",size=16,weight="bold")

        w=OptionMenu(self.frame_top,variable, *users,command=self.changeuser)
        w.config(font=self.font)
        w.pack()

        self.buttonFrame1 = Frame(master=self.root,relief=tk.RAISED,borderwidth=5)
        self.buttonFrame1.pack(pady=20)
        self.button1 = Button(self.buttonFrame1, text="display groups", bg="white", fg="black", pady=5, padx=5, command=self.groups_display,font=self.font)
        self.button1.pack(side='left')
        self.button2 = Button(self.buttonFrame1, text="display contacts", bg="white", fg="black", pady=5, padx=5, command=self.contact_display,font=self.font)
        self.button2.pack(side='right')
        self.button3 = Button(self.buttonFrame1, text="received messages", bg="white", fg="black", pady=5, padx=5, command=self.received,font=self.font)
        self.button3.pack(side='left')
        self.button4 = Button(self.buttonFrame1, text="post message", bg="white", fg="black", pady=5, padx=5, command=self.send,font=self.font)
        self.button4.pack(side='right')

        

        

        self.frame_out = Frame(self.root)
        self.frame_out.pack(fill=BOTH,expand=1)

        self.plot = Frame(self.frame_out, width=200, height=200)
        self.plot.pack(side=RIGHT,expand=True,fill=tk.BOTH)

    def changeuser(self,selection):
        #print(selection)
        self.current_user=selection

    def getFields(self):
        photobox=tk.filedialog.askopenfilename(title='open')
        self.image_loc.append(photobox)
        img = Image.open(photobox)
        img = img.resize((250, 250), Image.ANTIALIAS)
        img = ImageTk.PhotoImage(img)
        panel = Label(self.root, image=img)
        panel.image = img
        panel.pack()


    def received(self):
        for i in self.data_usr:
            if i.id ==  self.current_user:
                recieved_window = rm.incoming(i,self.data_grp)
                recieved_window.run()
                return

    def send(self):
        for i in self.data_usr:
            if i.id ==  self.current_user:
                send_window = pm.post(i,self.data_usr,self.data_grp)
                send_window.run()
                return
    
    def groups_display(self):
        for i in self.data_usr:
            if i.id ==  self.current_user:
                disply = dg.display_group(i)
                disply.run()
                return

    def contact_display(self):
        for i in self.data_usr:
            if i.id ==  self.current_user:
                display = cd.display_contacts(i)
                display.run()
                return

    def run(self):
        self.root.mainloop()