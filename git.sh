#!/bin/bash

# Start the ssh-agent in the background.
eval "$(ssh-agent -s)"
#Adds waiting for the ssh-agent to be initialized
sleep 1
ssh-add ~/.ssh/github
