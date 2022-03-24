Purpose of this Project: Show usage of new passord pages introduced with Mect Suite 3.4.0

In automation.cpp you will find one cpp function:

u_int32_t getMSVersion()

The result of this function is the Mect Suite version number installed on taget (parsed form system file /rootfs_version)
in hex form. Eg, for version 3.3.9 the result is 0x00030309

The purpose of this function is to prevent page100.cpp from using the pages if a version of Mect Suite prior to 3.3.10 is present on the target.

In this project there are four pages with different levels of user authorizazion:

page100:	Enabled for all user levels (protection_level = pwd_operator_e)
page200:	Enabled for "User" level and above (protection_level = pwd_user_e)
page300:	Enabled for "SuperUser" level and above (protection_level = pwd_super_user_e)
page400:	Enabled for "Admin" level only (protection_level = pwd_admin_e)

page100 has two ATCMbuttons to call the new system pages for login and password management introduced with MS 3.4.0:

atcmButtonPassword to call the new system page "login_pwd" to enable user login and user password change

atcmButtonSetPwd to call the new system page "set_password" for password management. 
This page displays the passwords in clear text and allows the forcing of the three password levels. 
It should be called in user applications in a secure manner using a password protected atcmButton



