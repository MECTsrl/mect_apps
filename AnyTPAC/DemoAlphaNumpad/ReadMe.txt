Purpose of this Project: Show usage of new methods of AlphaNumpad object introduced with Mect Suite 3.4.2

In this project you will find 2 pages, page100 and page200.

Both pages have, as a private property of the class, a myKeyboard pointer to an AlphaNumpad object (virtual alphanumeric keyboard).

The AlphaNumpad object is allocated only once during the creation of the page, and can be reused infinite times in the code of the page itself, optimizing the use of memory and reducing the loading and display time of the virtual keyboard.

When needed (see the on_pushButtonOnce_clicked () function) set the default value to be edited in the virtual keyboard, two setters are available, setQStringValue(const QString & stringValue) and setValue(char * value).
They both do the same thing.

If the virtual keyboard should not display a default value, simply call setQStringValue("")

It is also possible to set a title (prompt) for the virtual keyboard with the setPrompt(QString) method

To obtain the value typed and confirmed by the user (myKeyboard-> exec () == QDialog :: Accepted) there are two getters: QString getQStringValue(); and void getValue(char * value);
After recovering the edited value it is sufficient to hide the virtual keyboard with the hide() method.

If the virtual keyboard was created with the bool password = true parameter to enable masking of the typed text, you can enable or disable masking with the setTextMasked(bool isMasked) method;

