from social_network import *

class group(Social_network):
    def __init__(self,id):
        Social_network.__init__(self,id)
        self.members=[]
        self.message=[]

    def update_members(self,member):
        if(member[-1]=='>'):
            member=member[0:-1]
        self.members.append(member)

    def new_message(self,type,sendedby,message):
        self.message.append((type,sendedby,message))
        