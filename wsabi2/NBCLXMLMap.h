//
//  NBCLXMLMap.h
//  wsabi2
//
//  Created by Matt Aronoff on 3/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBCLXMLMap : NSObject

//Obj-C to XML
+(id) objcObjectForXML:(NSString*)contentString ofType:(NSString*)typeString;

//XML to Obj-C
+(NSString*) xmlElementForObject:(id)sourceObject withElementName:(NSString*)elementName;

@end
