## Subdirectories for each project.

#### EVEE_POC_PCB2
Includes most of EVEE_POC_PWM but with more emphasis on motor control

#### EVEE_POC_PWM
Contains code to communicate with NFC reader. Toggles LED based on ID of tag

## EVEE_POC_PCB2.sls
This file is a good starting point for new projects (as of 1/20/22)
To import: download/pull this file, open simplicity studio v5, go to file>import, browse to the directory where the sls is saved and hit open, the import wizard will now show the project under detected projects, finally hit next to proceed through import.

After import delete the src file within the project if one is auto generated.

See these links for how to configure SSv5.

Internal Team Doc:
https://docs.google.com/document/d/1ju000s5zF7HjwI6fxCQPvtVg8PwAd9hC_2gIVASs3nM/edit

External SI Doc:
https://community.silabs.com/s/article/debugging-an-efm32-product-on-a-custom-board?language=en_US   

Note: if you want to rename the project it is best to do it in the import menu before hitting finish. 
