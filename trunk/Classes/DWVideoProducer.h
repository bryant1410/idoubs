/*
 * Copyright (C) 2010 Mamadou Diop.
 *
 * Contact: Mamadou Diop <diopmamadou(at)doubango.org>
 *       
 * This file is part of idoubs Project (http://code.google.com/p/idoubs)
 *
 * idoubs is free software: you can redistribute it and/or modify it under the terms of 
 * the GNU General Public License as published by the Free Software Foundation, either version 3 
 * of the License, or (at your option) any later version.
 *       
 * idoubs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 * See the GNU General Public License for more details.
 *       
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#import <Foundation/Foundation.h>

#include "tinymedia/tmedia_producer.h"

@class DWVideoProducer;

typedef struct dw_producer_s
{
	TMEDIA_DECLARE_PRODUCER;
	
	DWVideoProducer* eProducer;
	int negociatedFps;
	int negociatedWidth;
	int negociatedHeight;
	
	tsk_bool_t started;
}
dw_producer_t;

extern const tmedia_producer_plugin_def_t *dw_videoProducer_plugin_def_t;

int dw_producer_push(dw_producer_t* producer, const void* buffer, tsk_size_t size);

@protocol DWVideoProducerCallback
-(int)producerStarted:(dw_producer_t*)producer;
-(int)producerPaused:(dw_producer_t*)producer;
-(int)producerStopped:(dw_producer_t*)producer;
-(int)producerPrepared:(dw_producer_t*)producer;
-(int)producerCreated:(dw_producer_t*)producer;
-(int)producerDestroyed:(dw_producer_t*)producer;
@end


@interface DWVideoProducer : NSObject {
	NSObject<DWVideoProducerCallback>* callback;
}

+(DWVideoProducer*)sharedInstance;

@property(readwrite, retain) NSObject<DWVideoProducerCallback>* callback;

@end
