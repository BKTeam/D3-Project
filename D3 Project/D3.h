//
//  D3_Project.h
//  D3 Project
//
//  Created by stevie nguyen on 6/10/13.
//  Copyright (c) 2013 BK Team. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NSString* (^keyFunction) (id object);
/*
 
 Cấu trúc cây của một dữ liệu bảng (được thể hiện qua một array với mỗi phần tử là NSDictionary)
 
 */
@interface D3Nest : NSMutableDictionary
@property (nonatomic, strong) NSMutableArray* keys;

- (void) registerKey: (keyFunction) key;
- (void) sortKeysWithAscending: (BOOL) ascending;
- (void) sortValuesWithAscending: (BOOL) ascending;
- (void) rollUp;

- (id) entries: (NSArray*) array;

@end

@interface D3 : NSObject

//  Trả về -1 nếu a < b, trả về 1 nếu a > b, trả về 0 trong các trường hợp khác
- (NSInteger) ascendingWithFirstNumber: (NSNumber*) a
                          SecondNumber: (NSNumber*) b;

//  Trả về 1 nếu a < b, trả về -1 nếu a > b, trả về 0 trong các trường hợp khác
- (NSInteger) decendingWithFirstNumber: (NSNumber*) a
                          SecondNumber: (NSNumber*) b;

//  Trả về phần tử nhỏ nhất thoả mãn điều kiện hàm accessor (nếu accessor = nil thì duyệt toàn bộ mảng )
- (NSValue*) minOfArray: (NSArray*) array
         accessor: (BOOL (^)(id)) accessor;

//  Trả về phần tử lớn nhất thoả mãn điều kiện hàm accessor (nếu accessor = nil thì duyệt toàn bộ mảng )
- (NSValue*) maxOfArray: (NSArray*) array
         accessor: (BOOL (^)(id)) accessor;

//  Trả về mảng chứa phần tử lớn nhất và nhỏ nhất thoả mãn điều kiện hàm accessor (nếu accessor = nil thì duyệt toàn bộ mảng )
- (NSArray*) extentOfArray: (NSArray*) array
                  accessor: (BOOL (^)(id)) accessor;

//  Tính tổng của các phần tử thoả mãn điều kiện hàm accessor (nếu accessor = nil thì duyệt toàn bộ mảng )
- (NSNumber*) sumOfArray: (NSArray*) array
                accessor: (BOOL (^)(id)) accessor;

//  Tính trung bình cộng của các phần tử thoả mãn điều kiện hàm accessor (nếu accessor = nil thì duyệt toàn bộ mảng )
- (NSNumber*) meanOfArray: (NSArray*) array
                 accessor: (BOOL (^)(id)) accessor;

//  Tính trung bình nhân của các phần tử thoả mãn điều kiện hàm accessor (nếu accessor = nil thì duyệt toàn bộ mảng )
- (NSNumber*) medianOfArray: (NSArray*) array
                   accessor: (BOOL (^)(id)) accessor;

//  Chưa hiểu rõ lắm là cái gì
- (NSValue*) quantileOfArray: (NSArray*) array
                           p: (NSNumber*) p;

//  Xáo trộn mảng
- (void) shuffle: (NSMutableArray*) array;

//  Ghép các phần tử của mảng lại với nhau, nếu một phần tử là một mảng thì lại phân rã mảng đó thành các phần tử.
- (NSArray*) mearge: (NSArray*) array, ... NS_REQUIRES_NIL_TERMINATION;

//  Tạo thành một dãy cấp số cộng với phần tử đầu là start, cấp số cộng là step và phần tử cuối < stop nếu step >0 ( và > stop nếu step < 0 ). Nếu rơi vào trường hợp vòng lặp vô hạn thì throw ra error. Ví dụ rangeWithStart: 0 Stop: 10 Step: 1.5 ==> Trả về [0 1.5 3 4.5 6 7.5 9]
- (NSArray*) rangeWithStart: (NSNumber*) start
                       Stop: (NSNumber*) stop
                       Step: (NSNumber*) step
                      Error: (NSError**) error;

//  Trả về một mảng với số phần tử = số phần tử của indexes và phần tử thứ i thì = phần tử thứ indexes[i] của array. Ví dụ array: [ a b c d e ] indexes: [ 2 0] => trả về [ c a ]. Trả về nil nếu có 1 index không hợp lệ
- (NSArray*) permuteWithArray: (NSArray*) array
                      Indexes: (NSArray*) indexes;

//  Trả về một mảng của một mảng. Phần tử thứ i của mảng trả về là một mảng với các phần tử là phần tử thứ i của các mảng đầu vào tương ứng. Mảng trả về có số phần tử = số phần tử của mảng đầu vào có ít phần tử nhất. Ví dụ đầu vào: [ a b c ]; [ d e f g ]; [ h i j k l m ] => trả về [ [ a d h ]; [ b e i ]; [ c f j ] ]
- (NSArray*) zip: (NSArray*) array, ... NS_REQUIRES_NIL_TERMINATION;

//  Trả về một object D3Nest rỗng
- (D3Nest*) nest;
@end
