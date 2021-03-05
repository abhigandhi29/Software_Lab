from social_network import *

class user(Social_network):
    def __init__(self,id):
        Social_network.__init__(self,id)
        self.contacts=[]
        self.message=[]
        self.group=[]

    def update_contacts(self,contact1):
        if(contact1[-1]=='>'):
            contact1=contact1[0:-1]
        self.contacts.append(str(contact1))

    def new_message(self,type,sended_by,message):
        self.message.append((type,sended_by,message))

    def update_group(self,group):
        self.group.append(group)
        