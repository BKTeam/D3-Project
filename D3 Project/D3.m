//
//  D3_Project.m
//  D3 Project
//
//  Created by stevie nguyen on 6/10/13.
//  Copyright (c) 2013 BK Team. All rights reserved.
//

#import "D3.h"

@implementation D3Nest

- (id) init{
    if (self = [super init]) {
        _keys = [NSMutableArray new];
    }
    return self;
}

- (void) registerKey:(keyFunction)key{
    [_keys addObject:key];
}

- (id) entries:(NSArray *)array{
    if (_keys.count == 0) {
        return array;
    }
    while (_keys.count >= 1) {
        keyFunction function = [_keys objectAtIndex:0];
        [_keys removeObjectAtIndex:0];
        
        NSMutableArray* keyExtracted = [NSMutableArray new];
        for ( id object in array ) {
            NSString* key = function(object);
            if ([keyExtracted indexOfObject:key] == NSNotFound) {
                [keyExtracted addObject:key];
                NSMutableArray* children = [NSMutableArray arrayWithObject:object];
                [self setObject:children forKey:key];
            }
            else{
                
            }
        }
    }
}

@end

@implementation D3

- (D3Nest*) nest{
    return [D3Nest new];
}

@end
