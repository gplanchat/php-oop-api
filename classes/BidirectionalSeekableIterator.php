<?php

namespace Spl;

/**
 * Note: extends Iterator instead of SeekableIterator due to E_STRICT
 * thrown when a 2nd parameter is added to seek()
 */
interface BidirectionalSeekableIterator
    extends \Iterator
{
    const SEEK_SET = 0;
    const SEEK_CUR = 1;
    const SEEK_END = 2;

    /**
     * @param BidirectionalSeekableIterator $friend
     * @return int
     */
    public function distance(BidirectionalSeekableIterator $friend);

    /**
     * @param int $offset
     * @return void
     */
    public function previous($offset = 1);

    /**
     * @param int $offset
     * @return void
     */
    public function next($offset = 1);

    /**
     * @return integer
     */
    public function index();

    /**
     * @return void
     */
    public function end();
}