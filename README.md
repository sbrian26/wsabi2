
#wsabi v2.0
##External libraries
wsabi has references to the following external libraries  

* [GMGridView](https://github.com/gmoledina/GMGridView)  
	* MODIFICATION NOTES
        * GMGridView.m has been modified to prevent automatic deletion without confirmation.
        * GMGridViewCell now adds the full size view to the root view controller, not the current cell. (Changes in GMGridViewCell and GMGridView)
* [ActionSheetPicker](FillThis)
    * MODIFICATION NOTES
        * Added a "neverPresentInPopover" variable to AbstractActionSheetPicker to prevent launching a popover from inside another popover (which is against the iPad HIG)
        * Added direct access to the DatePicker, to allow for configuration.
* [ELCTextFieldCell](https://github.com/elc/ELCTextFieldCell)
    * MODIFICATION NOTE: Had to update this for ARC compatibility
* [Lumberjack](https://github.com/robbiehanson/CocoaLumberjack)
	* This is used for logging, particularly by the user testing additions.

##Design notes
* WSCDDeviceDefinition stores modalities and submodalities as delimited strings, not as arrays. The reason is that we need to be able to quickly filter all available device defs to present the "recent sensors" list, and arrays (which are stored as blobs) are not searchable. Further, these aren't going to be particularly large strings – even when including all submodalities for all modalities.
 
##Logging
The touch log files contain data in the following format:  
	
	Timestamp,Class,FrameX,FrameY,FrameW,FrameH,TouchX,TouchY,TouchType


##Technical Debt, or Here's some outstanding stuff that should really be fixed.  
* Unbelievably, the non-keyboard-hiding behavior in the sensor walkthrough is actually NOT a bug, according to Apple. [linky.](http://stackoverflow.com/questions/8379205/uitextfields-keyboard-wont-dismiss-no-really) It really does still need to be addressed.  
* The WSCDPerson->WSCDItem relationship should be ordered to reflect the fact that the items are, conceptually, ordered. However, there's a longstanding bug in Apple's Core Data code which makes this impractical for the time being ([source](http://stackoverflow.com/questions/7385439/problems-with-nsorderedset)). It's my feeling that a custom overridden setter for an autogenerated property is uglier than just including some sort of index in the data model itself.  
* There has GOT to be a cleaner way to do the modality/sensor setup walkthrough. Four separate controllers seems insane.  
    
